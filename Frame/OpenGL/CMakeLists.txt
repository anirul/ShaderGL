# Frame OpenGL.

add_library(FrameOpenGL
  STATIC
    Buffer.cpp
    Buffer.h
    Device.cpp
    Device.h
    Fill.cpp
    Fill.h
    FrameBuffer.cpp
    FrameBuffer.h
    Light.cpp
    Light.h
    Material.cpp
    Material.h
    StaticMesh.cpp
    StaticMesh.h
    Pixel.cpp
    Pixel.h
    Program.cpp
    Program.h
    RenderBuffer.cpp
    RenderBuffer.h
    Renderer.cpp
    Renderer.h
    ScopedBind.cpp
    ScopedBind.h
    Shader.cpp
    Shader.h
    Texture.cpp
    Texture.h
)

target_include_directories(FrameOpenGL
  PUBLIC
    ${CMAKE_SOURCE_DIR}
    ${CMAKE_CURRENT_BINARY_DIR}
)

target_link_libraries(FrameOpenGL
  PUBLIC
    Frame
    FrameFile
    FrameOpenGLFile
    FrameProto
    GLEW::GLEW
)

add_subdirectory(Test)
add_subdirectory(File)
