install(PROGRAMS select_column.py
    TYPE BIN)
install(DIRECTORY utils DESTINATION lib/python
    PATTERN "__pycache__" EXCLUDE
    PATTERN "*.bak" EXCLUDE
    PATTERN "*~" EXCLUDE)
