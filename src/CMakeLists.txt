add_executable(poj3267 poj3267.cpp) 
add_executable(poj2479 poj2479.cpp) 

set (target_names 
	poj3267
	poj2479 
	) 
	
install(TARGETS ${target_names} RUNTIME DESTINATION bin/) 