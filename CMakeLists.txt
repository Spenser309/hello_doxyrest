cmake_minimum_required(VERSION 3.13.2)
project(mla VERSION 0.0.1 DESCRIPTION "Hello DoxyRest")

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "-Wall -Werror")

find_package(Doxygen
        REQUIRED dot
        OPTIONAL_COMPONENTS mscgen dia)

set(DOXYGEN_GENERATE_XML YES)
set(DOXYGEN_EXTRACT_ALL YES)
set(DOXYGEN_ALIASES \"rst=\\xmlonly\" \"endrst=\\endxmlonly\")
set(DOXYGEN_WARN_AS_ERROR YES)
set(DOXYGEN_WARN_IF_UNDOCUMENTED YES)
set(DOXYGEN_PREDEFINED DOXYGEN_SHOULD_SKIP_THIS)
doxygen_add_docs(doxygen hello COMMENT "Generate Doxygen")

add_subdirectory(docs)

find_package(Python3 REQUIRED Interpreter)

add_subdirectory(hello)
