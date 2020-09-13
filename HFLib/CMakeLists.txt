add_library( HFLib 
	src/HarmonicField.cpp
	)

target_include_directories( HFLib 
	PUBLIC 
		$<INSTALL_INTERFACE:include>    
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
	)

