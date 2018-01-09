add_subdirectory(Package_consolidation)

MAP_ADD_STR(hdrs "${PROJECT_NAME}/" headers)
set(headers ${headers} PARENT_SCOPE)
