% ************************************************************************
% - Ejercicios de José A. Alonso Jiménez
% "Ejercicios de Programación Declarativa con Prolog"
%
% - Puede encontrar más información en:
% https://www.cs.us.es/~jalonso/publicaciones/2006-ej_prog_declarativa.pdf
% ************************************************************************

% ----- PERMUTACION -----
% 
% Función -> permutacion(+Lis1, ?Lis2)
%
% ***|Se verifica si Lis2 es una permutación de la lista
% ***|Lis1 
%
% --------------------------

% -- Principio de Inducción --
%
%	1. P(N0)
%	2. N > N0, P(N-1) -> P(N)

% Hallamos el caso base
permutacion([], []).

% Hallamos el caso N - 1
permutacion(Lis1, [Cab|Resto]) :- select(Cab, Lis1, Res), permutacion(Resto, Res).