add_library( HFLib 
	"src/Field.cpp"
	"src/Filter.cpp"
	)

target_include_directories( HFLib 
	PUBLIC 
		$<INSTALL_INTERFACE:include>    
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
	)

