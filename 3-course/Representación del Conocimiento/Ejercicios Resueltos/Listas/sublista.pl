% ************************************************************************
% - Ejercicios de José A. Alonso Jiménez
% "Ejercicios de Programación Declarativa con Prolog"
%
% - Puede encontrar más información en:
% https://www.cs.us.es/~jalonso/publicaciones/2006-ej_prog_declarativa.pdf
% ************************************************************************

% ----- SUBLISTA -----
% 
% Función -> sublista(+Lis1, -Lis2)
%
% ***|Se verifica si Lis1 es una sublista de Lis2
% ***|esta sublista tendrá 2 elementos.
%
% --------------------------

% -- Principio de Inducción --
%
%	1. P(N0)
%	2. N > N0, P(N-1) -> P(N)

% Hallamos el caso base
sublista([Ele1, Ele2], [Ele1, Ele2|_]).

% Hallamos el caso N - 1
sublista(Lis1, [_|RestoI]) :- sublista(Lis1, RestoI).