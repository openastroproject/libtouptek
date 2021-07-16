cmake_minimum_required ( VERSION 3.0 )

project ( libtouptek-full VERSION 0.1 )

include_directories ( SYSTEM include )

add_subdirectory ( src )
add_subdirectory ( tests )
