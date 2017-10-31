add_executable (${CMAKE_PROJECT_NAME}
    # ... probably other files here seaprated by space or newline... 
    demo.cpp)

# This is all we need to do to "include" the date library
target_link_libraries(${CMAKE_PROJECT_NAME} date)

include(GNUInstallDirs)

INSTALL(TARGETS ${CMAKE_PROJECT_NAME}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR})
