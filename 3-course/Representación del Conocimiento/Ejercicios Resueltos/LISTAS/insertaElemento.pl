% ************************************************************************
% - Ejercicios de José A. Alonso Jiménez
% "Ejercicios de Programación Declarativa con Prolog"
%
% - Puede encontrar más información en:
% https://www.cs.us.es/~jalonso/publicaciones/2006-ej_prog_declarativa.pdf
% ************************************************************************

% ------ INSERTA ELEMENTO ------
%
% Función -> inserta(?X, ?L1, ?L2)
%
% ***|Se verifica si L2 unifica con la lista
% ***|L1 añadiendo el elemento X en cualquier
% ***|posición.
% ---------------------------------------

% -- Principio de Inducción --
%
%    1. P(N0)
%    2. N > N0, P(N-1) -> P(N)

% Hallamos el caso base
inserta(Ele, Lista, [Ele|Lista]).

% Hallamos la recursividad
inserta(Ele, [Cab|Resto], [Cab|RestoI]) :-
    inserta(Ele, Resto, RestoI).
