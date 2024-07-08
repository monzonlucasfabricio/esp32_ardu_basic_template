idf_component_register(SRCS "stdintf.c"
                    INCLUDE_DIRS "include")
                    
target_link_libraries(${COMPONENT_LIB} "-T ${CMAKE_CURRENT_SOURCE_DIR}/custom_linker.ld")