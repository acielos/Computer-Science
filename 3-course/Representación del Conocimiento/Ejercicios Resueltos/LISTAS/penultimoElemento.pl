% ************************************************************************
% - Ejercicios de José A. Alonso Jiménez
% "Ejercicios de Programación Declarativa con Prolog"
%
% - Puede encontrar más información en:
% https://www.cs.us.es/~jalonso/publicaciones/2006-ej_prog_declarativa.pdf
% ************************************************************************

% ------ PENULTIMO ELEMENTO ------
%
% Función -> pultimo(?X, ?L)
%
% ***|Se verifica si X unifica con el
% ***|penultimo elemento de la lista L
%
% ---------------------------------------

% -- Principio de Inducción --
%
%    1. P(N0)
%    2. N > N0, P(N-1) -> P(N)

% Hallamos el caso base
pultimo(Ele, [Ele, _]).

% Hallamos la recursividad
pultimo(Ele, [_|Resto]) :-
    pultimo(Ele, Resto).
