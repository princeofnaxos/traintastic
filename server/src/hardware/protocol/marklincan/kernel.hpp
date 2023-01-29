/**
 * server/src/hardware/protocol/marklincan/kernel.hpp
 *
 * This file is part of the traintastic source code.
 *
 * Copyright (C) 2023 Reinder Feenstra
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

#ifndef TRAINTASTIC_SERVER_HARDWARE_PROTOCOL_MARKLINCAN_KERNEL_HPP
#define TRAINTASTIC_SERVER_HARDWARE_PROTOCOL_MARKLINCAN_KERNEL_HPP

#include <memory>
#include <thread>
#include <boost/asio/io_context.hpp>
#include "config.hpp"
#include "iohandler/iohandler.hpp"

class Decoder;
enum class DecoderChangeFlags;
class DecoderController;

namespace MarklinCAN {

struct Message;

class Kernel
{
  private:
    boost::asio::io_context m_ioContext;
    std::unique_ptr<IOHandler> m_ioHandler;
    const bool m_simulation;
    std::thread m_thread;
    std::string m_logId;
    std::function<void()> m_onStarted;

    DecoderController* m_decoderController;

    Config m_config;
#ifndef NDEBUG
    bool m_started;
#endif

    Kernel(const Config& config, bool simulation);

    void setIOHandler(std::unique_ptr<IOHandler> handler);

    void send(const Message& message);
    void postSend(const Message& message);

  public:
    Kernel(const Kernel&) = delete;
    Kernel& operator =(const Kernel&) = delete;

#ifndef NDEBUG
    bool isKernelThread() const
    {
      return std::this_thread::get_id() == m_thread.get_id();
    }
#endif

    /**
     * \brief IO context for kernel and IO handler
     *
     * \return The IO context
     */
    boost::asio::io_context& ioContext() { return m_ioContext; }

    /**
     * \brief Create kernel and IO handler
     *
     * \param[in] config Configuration
     * \param[in] args IO handler arguments
     * \return The kernel instance
     */
    template<class IOHandlerType, class... Args>
    static std::unique_ptr<Kernel> create(const Config& config, Args... args)
    {
      static_assert(std::is_base_of_v<IOHandler, IOHandlerType>);
      std::unique_ptr<Kernel> kernel{new Kernel(config, isSimulation<IOHandlerType>())};
      kernel->setIOHandler(std::make_unique<IOHandlerType>(*kernel, std::forward<Args>(args)...));
      return kernel;
    }

    /**
     * \brief Access the IO handler
     *
     * \return The IO handler
     * \note The IO handler runs in the kernel's IO context, not all functions can be called safely!
     */
    template<class T>
    T& ioHandler()
    {
      assert(dynamic_cast<T*>(m_ioHandler.get()));
      return static_cast<T&>(*m_ioHandler);
    }

    /**
     * \brief Get object id used for log messages
     * \return The object id
     */
    inline const std::string& logId()
    {
      return m_logId;
    }

    /**
     * \brief Set object id used for log messages
     *
     * \param[in] value The object id
     */
    void setLogId(std::string value) { m_logId = std::move(value); }

    /**
     * \brief Set configuration
     *
     * \param[in] config The configuration
     */
    void setConfig(const Config& config);

    /**
     * \brief ...
     *
     * \param[in] callback ...
     * \note This function may not be called when the kernel is running.
     */
    void setOnStarted(std::function<void()> callback);

    /**
     * \brief Set the decoder controller
     * \param[in] decoderController The decoder controller
     * \note This function may not be called when the kernel is running.
     */
    void setDecoderController(DecoderController* decoderController);

    /**
     * \brief Start the kernel and IO handler
     */
    void start();

    /**
     * \brief Stop the kernel and IO handler
     */
    void stop();

    /**
     * \brief ...
     *
     * This must be called by the IO handler whenever a Marklin CAN message is received.
     *
     * \param[in] message The received Marklin CAN message
     * \note This function must run in the kernel's IO context
     */
    void receive(const Message& message);

    void systemStop();
    void systemGo();
    void systemHalt();

    void decoderChanged(const Decoder& decoder, DecoderChangeFlags changes, uint32_t functionNumber);
};

}

#endif
