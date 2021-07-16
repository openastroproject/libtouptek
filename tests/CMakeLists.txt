cmake_minimum_required ( VERSION 3.0 )

project ( tests VERSION 0.1 )

add_executable ( toupcam-list toupcam-list.c )
target_link_libraries ( toupcam-list PUBLIC touptek -lusb-1.0 )

add_executable ( altaircam-list altaircam-list.c )
target_link_libraries ( altaircam-list PUBLIC touptek -lusb-1.0 )
