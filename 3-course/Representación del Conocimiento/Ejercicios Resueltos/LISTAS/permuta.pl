% ************************************************************************
% - Ejercicios de José A. Alonso Jiménez
% "Ejercicios de Programación Declarativa con Prolog"
%
% - Puede encontrar más información en:
% https://www.cs.us.es/~jalonso/publicaciones/2006-ej_prog_declarativa.pdf
% ************************************************************************

% --------------- PERMUTA ---------------
%
% Función -> permuta(?L1, ?L2)
%
% ***|Se verifica si L2 unifica con una permutación
% ***|de L1
% ---------------------------------------

% -- Principio de Inducción --
%
%    1. P(N0)
%    2. N > N0, P(N-1) -> P(N)

% Hallamos el caso base
permuta([], []).

% Hallamos la recursividad
permuta(L1, [Cab|Resto]) :-
    eliminaElemento(Cab, L1, L3),
    permuta(L3, Resto).

% ----- FUNCIONES AUXILIARES -----

% --------------------------------------------
% Función ->eliminaElemento(?X, ?L1, ?L2)
%
% ***|Se verifica si L2 unifica con la lista
% ***|L1 eliminando una ocurrencia de X
% --------------------------------------------

eliminaElemento(Ele, [Ele|Resto], Resto).

eliminaElemento(Ele, [Cab|Resto], [Cab|RestoI]) :-
    eliminaElemento(Ele, Resto, RestoI).
