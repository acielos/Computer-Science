% ************************************************************************
% - Ejercicios de José A. Alonso Jiménez
% "Ejercicios de Programación Declarativa con Prolog"
%
% - Puede encontrar más información en:
% https://www.cs.us.es/~jalonso/publicaciones/2006-ej_prog_declarativa.pdf
% ************************************************************************

% ----- ELEMENTOS IGUALES -----
% 
% Función -> todoIgual(+Lis)
%
% ***|Se verifica si todos los elementos de Lis son iguales
%
% --------------------------

% -- Principio de Inducción --
%
%	1. P(N0)
%	2. N > N0, P(N-1) -> P(N)

% Hallamos el caso base
todoIgual([]).
todoIgual([_]).

% Hallamos el caso N - 1
todoIgual([Ele, Ele|Resto]) :- todoIgual([Ele|Resto]).