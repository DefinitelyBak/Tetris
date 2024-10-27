add_library(
    Model
  ##SHARED пока не разобрался как правильно работать с shared library
    ${CMAKE_CURRENT_SOURCE_DIR}/Source/Model.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Source/Blocks/AbstractShape.cpp
    #${CMAKE_CURRENT_SOURCE_DIR}/Source/OrderLineHash.cpp
    #${CMAKE_CURRENT_SOURCE_DIR}/Source/Exception/OutOfStock.cpp
)

target_include_directories(
    Model 
  PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/Include
)

target_link_libraries(
    Model
  PUBLIC
    Common
)
