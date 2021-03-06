cmake_minimum_required(VERSION 2.6)

project(MMG)

include_directories(
	contrib/include
	src/MMG
	src/rend
)

link_directories(
	${CMAKE_SOURCE_DIR}/contrib/lib
)

add_definitions(-DSTD_SR1_DEBUG)

add_library(rend
	src/rend/Exception.cpp
	src/rend/Context.cpp
	src/rend/Texture.cpp
	src/rend/RenderTexture.cpp
	src/rend/Shader.cpp
	src/rend/Buffer.cpp
	src/rend/Mesh.cpp
	src/rend/Util.cpp
)
target_link_libraries(rend opengl32 glew32)

add_library(MMG
	src/MMG/MMG.h
	src/MMG/Input.h
	src/MMG/Input.cpp
	src/MMG/Camera.h
	src/MMG/Camera.cpp
	src/MMG/Environment.h
	src/MMG/Environment.cpp
	src/MMG/ResourceManager.h
	src/MMG/ResourceManager.cpp
	src/MMG/Resource.h
	src/MMG/Resource.cpp
	src/MMG/Model.h
	src/MMG/Model.cpp
	src/MMG/Material.h
	src/MMG/Material.cpp
	src/MMG/Sound.h
	src/MMG/Sound.cpp
	src/MMG/Core.h
	src/MMG/Core.cpp
	src/MMG/Entity.h
	src/MMG/Entity.cpp
	src/MMG/Component.h
	src/MMG/Component.cpp
	src/MMG/MeshRenderer.h
	src/MMG/MeshRenderer.cpp
	src/MMG/SoundSource.h
	src/MMG/SoundSource.cpp
	src/MMG/BoxCollider.h
	src/MMG/BoxCollider.cpp
)
target_link_libraries(MMG rend SDL2 SDL2main OpenAL32)

add_executable(demo
	src/demo/Cat.h
	src/demo/Cat.cpp
	src/demo/Musician.h
	src/demo/Musician.cpp
	src/demo/CameraController.h
	src/demo/CameraController.cpp
	src/demo/main.cpp
)
target_link_libraries(demo MMG)

add_custom_command(TARGET demo
	POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy
		"${PROJECT_SOURCE_DIR}/contrib/lib/SDL2.dll"
		$<TARGET_FILE_DIR:demo>
	COMMAND ${CMAKE_COMMAND} -E copy
		"${PROJECT_SOURCE_DIR}/contrib/lib/glew32.dll"
		$<TARGET_FILE_DIR:demo>
	COMMAND ${CMAKE_COMMAND} -E copy
		"${PROJECT_SOURCE_DIR}/contrib/lib/OpenAL32.dll"
		$<TARGET_FILE_DIR:demo>
)
