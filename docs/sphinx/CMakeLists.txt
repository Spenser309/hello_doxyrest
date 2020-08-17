set(SPHINX_OPTS -W --keep-going ${CMAKE_CURRENT_BINARY_DIR})

find_package(doxyrest REQUIRED)

message("DOXYREST_INSTALL_PREFIX = ${DOXYREST_INSTALL_PREFIX}")

configure_file(conf.py.in conf.py)
file(GLOB_RECURSE DOC_FILES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *)

foreach(DOC_FILE ${DOC_FILES})
  configure_file(${DOC_FILE} ${DOC_FILE} COPYONLY)
endforeach(DOC_FILE)

add_custom_target(sphinx-docs
  COMMAND rm -rf ${CMAKE_CURRENT_BINARY_DIR}/{cpp-api,_build} && mkdir -p ${CMAKE_CURRENT_BINARY_DIR}/cpp-api
  COMMAND ${DOXYREST_EXE} ${CMAKE_BINARY_DIR}/xml/index.xml
    -F ${DOXYREST_FRAME_DIR}/common
    -F ${DOXYREST_FRAME_DIR}/cfamily/
    -f index.rst.in
    -c ${DOXYREST_FRAME_DIR}/doxyrest-config.lua
    -o cpp-api/index.rst
  COMMAND sphinx-build -b html ${SPHINX_OPTS} _build/html
  DEPENDS doxygen
  COMMENT "Sphinx Docs"
)

