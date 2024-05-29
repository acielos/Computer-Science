
% elem_enesimo(+Pos, +Lista, -Elem)
% Es cierto cuando Elem unifica con el elemento que ocupa la posición Pos
% dentro de Lista.

elem_enesimo(1, [Cab|_], Cab).
elem_enesimo(N, [Cab|Resto], E) :- N > 1, N2 is N - 1, elem_enesimo(N2, Resto, Elem).

