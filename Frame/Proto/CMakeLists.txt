# Frame Proto.

add_library(FrameProto
  STATIC
    ParseMaterial.cpp
    ParseMaterial.h
    ParsePixel.cpp
    ParsePixel.h
    ParseProgram.cpp
    ParseProgram.h
    ParseSceneTree.cpp
    ParseSceneTree.h
    ParseTexture.cpp
    ParseTexture.h
    ParseUniform.cpp
    ParseUniform.h
    ParseLevel.cpp
    ParseLevel.h
    ProtoLevelCreate.cpp
    ProtoLevelCreate.h
    Level.proto
    Material.proto
    Math.proto
    Pixel.proto
    Program.proto
    Proto.cpp
    Proto.h
    Scene.proto
    Size.proto
    Texture.proto
    Uniform.proto
)

target_include_directories(FrameProto 
  PUBLIC 
    ${CMAKE_SOURCE_DIR}
    ${CMAKE_CURRENT_BINARY_DIR}
)

# I still doesn't know how to pass the path correctly to the generate in case
# there is any external include.
protobuf_generate(APPEND_PATH TARGET FrameProto)

target_link_libraries(FrameProto 
  PUBLIC
    Frame
    FrameOpenGL
    protobuf::libprotoc
    protobuf::libprotobuf
)

add_subdirectory(Test)
