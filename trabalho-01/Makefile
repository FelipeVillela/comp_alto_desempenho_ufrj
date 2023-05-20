CC = gcc
FC = gfortran

C_SOURCES = c_program.c
FORTRAN_SOURCES = fortran_program.f90

C_EXECUTABLE = c_executable
FORTRAN_EXECUTABLE = fortran_executable

all: $(C_EXECUTABLE) $(FORTRAN_EXECUTABLE)

$(C_EXECUTABLE): $(C_SOURCES)
	$(CC) -o $@ $<

$(FORTRAN_EXECUTABLE): $(FORTRAN_SOURCES)
	$(FC) -o $@ $<

clean:
	rm -f $(C_EXECUTABLE) $(FORTRAN_EXECUTABLE)
