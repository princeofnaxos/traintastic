# Version
set(TRAINTASTIC_VERSION 0.0.2)

# Platform
if(UNIX AND NOT APPLE AND NOT MINGW)
  set(LINUX TRUE)
endif()

# CI/CD
if(DEFINED ENV{GITHUB_ACTIONS})
  message(STATUS "We're on GitHub Actions")

  if($ENV{GITHUB_REF_TYPE} EQUAL "branch")

    set(TRAINTASTIC_CODENAME "$ENV{CI_REF_NAME_SLUG}-$ENV{GITHUB_RUN_NUMBER}-$ENV{CI_SHA_SHORT}")

    if(LINUX)
      execute_process(COMMAND lsb_release -i -s OUTPUT_STRIP_TRAILING_WHITESPACE OUTPUT_VARIABLE LSB_RELEASE_ID)
      execute_process(COMMAND lsb_release -c -s OUTPUT_STRIP_TRAILING_WHITESPACE OUTPUT_VARIABLE LSB_RELEASE_CODENAME)

      string(TOLOWER ${LSB_RELEASE_ID} LSB_RELEASE_ID)
      string(TOLOWER ${LSB_RELEASE_CODENAME} LSB_RELEASE_CODENAME)

      message(STATUS "lsb_release id is ${LSB_RELEASE_ID}")
      message(STATUS "lsb_release codename is ${LSB_RELEASE_CODENAME}")

      set(DEBIAN_PACKAGE_VERSION_EXTRA "~${LSB_RELEASE_ID}~${LSB_RELEASE_CODENAME}~$ENV{CI_REF_NAME_SLUG}~$ENV{GITHUB_RUN_NUMBER}~$ENV{CI_SHA_SHORT}")
    endif()
  endif()
endif()

# Codename
if(TRAINTASTIC_CODENAME)
  add_definitions(-DTRAINTASTIC_CODENAME="${TRAINTASTIC_CODENAME}")
endif()

# Debug
message(STATUS "TRAINTASTIC_CODENAME=${TRAINTASTIC_CODENAME}")
message(STATUS "DEBIAN_PACKAGE_VERSION_EXTRA=${DEBIAN_PACKAGE_VERSION_EXTRA}")