cmake_minimum_required ( VERSION 3.0 )

project ( touptek VERSION 0.1 )

add_library ( ${PROJECT_NAME} cameras.c enumerate.c toupcam.c altaircam.c
		mallincam.c )
