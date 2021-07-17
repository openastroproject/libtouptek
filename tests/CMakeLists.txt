cmake_minimum_required ( VERSION 3.0 )

project ( tests VERSION 0.1 )

add_executable ( toupcam-list toupcam-list.c )
target_link_libraries ( toupcam-list PUBLIC touptek -lusb-1.0 )

add_executable ( altaircam-list altaircam-list.c )
target_link_libraries ( altaircam-list PUBLIC touptek -lusb-1.0 )

add_executable ( mallincam-list mallincam-list.c )
target_link_libraries ( mallincam-list PUBLIC touptek -lusb-1.0 )

add_executable ( starshootg-list starshootg-list.c )
target_link_libraries ( starshootg-list PUBLIC touptek -lusb-1.0 )

add_executable ( meadecam-list meadecam-list.c )
target_link_libraries ( meadecam-list PUBLIC touptek -lusb-1.0 )

add_executable ( nncam-list nncam-list.c )
target_link_libraries ( nncam-list PUBLIC touptek -lusb-1.0 )
