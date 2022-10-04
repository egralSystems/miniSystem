cmake_minimum_required(VERSION 3.16)

# Setup duktape
execute_process(
  COMMAND git submodule init
  COMMAND git submodule update 
  WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}  
)

set(JERRY_CMDLINE           OFF)
set(JERRY_CMDLINE_TEST      OFF)
set(JERRY_CMDLINE_SNAPSHOT  OFF)
set(JERRY_LIBFUZZER         OFF)
set(JERRY_PORT_DEFAULT      ON)
set(JERRY_EXT               ON)
set(JERRY_MATH              ON)
set(UNITTESTS               OFF)
set(DOCTESTS                OFF)

# Optional build settings
set(BUILD_SHARED_LIBS         OFF)
set(ENABLE_AMALGAM            OFF)
set(ENABLE_LTO                ON)
set(ENABLE_STRIP              ON)
set(ENABLE_COMPILE_COMMANDS   ON)

# Optional features
set(JERRY_CPOINTER_32_BIT           OFF)
set(JERRY_DEBUGGER                  OFF)
set(JERRY_ERROR_MESSAGES            OFF)
set(JERRY_EXTERNAL_CONTEXT          OFF)
set(JERRY_PARSER                    ON)
set(JERRY_LINE_INFO                 OFF)
set(JERRY_LOGGING                   OFF)
set(JERRY_MEM_STATS                 OFF)
set(JERRY_MEM_GC_BEFORE_EACH_ALLOC  OFF)
set(JERRY_PARSER_DUMP_BYTE_CODE     OFF)
set(JERRY_PROFILE                   "es.next")
set(JERRY_REGEXP_STRICT_MODE        OFF)
set(JERRY_REGEXP_DUMP_BYTE_CODE     OFF)
set(JERRY_SNAPSHOT_EXEC             OFF)
set(JERRY_SNAPSHOT_SAVE             OFF)
set(JERRY_SYSTEM_ALLOCATOR          OFF)
set(JERRY_VALGRIND                  OFF)
set(JERRY_VM_EXEC_STOP              OFF)
set(JERRY_GLOBAL_HEAP_SIZE          "(512)")
set(JERRY_GC_LIMIT                  "(0)")
set(JERRY_STACK_LIMIT               "(0)")
set(JERRY_GC_MARK_LIMIT             "(8)")



# jerryscript runtime
add_subdirectory(jerryscript)

# miniSystem library src
add_subdirectory(src)