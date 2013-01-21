add_executable(poj3267 poj3267.cpp) 
add_executable(poj2479 poj2479.cpp) 
add_executable(poj1050 poj1050.cpp)

set (target_names 
	poj1050
	poj3267
	poj2479 
	) 
	
install(TARGETS ${target_names} RUNTIME DESTINATION bin/) 