add_executable(
	sfse_serialization_interface_contract
	SerializationInterfaceContract.cpp
)

target_compile_features(
	sfse_serialization_interface_contract
	PRIVATE
		cxx_std_17
)

target_include_directories(
	sfse_serialization_interface_contract
	PRIVATE
		${PROJECT_SOURCE_DIR}
)

add_test(
	NAME sfse_serialization_interface_contract
	COMMAND sfse_serialization_interface_contract
)
