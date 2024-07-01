% ************************************************************************
% - Ejercicios de José A. Alonso Jiménez
% "Ejercicios de Programación Declarativa con Prolog"
%
% - Puede encontrar más información en:
% https://www.cs.us.es/~jalonso/publicaciones/2006-ej_prog_declarativa.pdf
% ************************************************************************

% ------------ LONGITUD PAR ------------
%
% Función -> par(+L)
%
% ***|Se verifica si la longitud de la lista
% ***|L es par
% ---------------------------------------

% -- Principio de Inducción --
%
%    1. P(N0)
%    2. N > N0, P(N-1) -> P(N)

% Hallamos el caso base
par([]).

% Hallamos la recursividad
par([_, _|Resto]) :-
    par(Resto).
