program matrix_vector_multiplication
    implicit none
    
    integer :: n, m, i, j, sum, max_number
    real :: random_n
    real, allocatable :: A(:,:), x(:), b(:)
    character(len=10) :: arg1, arg2
    
    ! Verifica o número de argumentos de linha de comando
    if (command_argument_count() /= 2) then
        write(*, *) "Usage: ./program_name <number of rows> <number of columns>"
        stop 1
    end if
    
    ! Lê os valores de entrada da linha de comando
    call get_command_argument(1, arg1)
    call get_command_argument(2, arg2)
    read(arg1, *) n
    read(arg2, *) m
    
    max_number = 100
    
    ! Aloca a matriz A
    allocate(A(n, m))
    
    ! Aloca os vetores x e b
    allocate(x(m))
    allocate(b(n))
    
    ! Inicializa o gerador de números aleatórios
    call random_seed()
    
    ! ! Gera valores aleatórios para a matriz A
    do i = 1, n
        do j = 1, m
            call random_number(random_n)
            A(i, j) = int(random_n * max_number)
        end do
    end do
    
    ! Gera valores aleatórios para o vetor x
    do i = 1, m
        call random_number(random_n)
        x(i) = int(random_n * max_number)
    end do
    
    ! Realiza a multiplicação matriz-vetor
    do i = 1, n
        sum = 0
        do j = 1, m
            sum = sum + A(i, j) * x(j)
            ! write(*, '(I0)') int(A(i, j))
            ! write(*, '(I0)') int(x(j))
        end do
        b(i) = sum
        ! Imprime o resultado
        ! write(*, "(A, $)")
        ! write(*, '(I0)') int(b(i))
        
    end do
    
    ! Libera a memória alocada
    deallocate(A, x, b)
    
end program matrix_vector_multiplication
