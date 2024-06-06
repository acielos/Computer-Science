% ************************************************************************
% - Ejercicios de José A. Alonso Jiménez
% "Ejercicios de Programación Declarativa con Prolog"
%
% - Puede encontrar más información en:
% https://www.cs.us.es/~jalonso/publicaciones/2006-ej_prog_declarativa.pdf
% ************************************************************************

% ----- Palíndromo -----
% 
% Función -> palindromo(+L)
%
% ***|Se verifica si la lista L unifica con un palíndromo
%
% --------------------------

% -- Principio de Inducción --
%
%	1. P(N0)
%	2. N > N0, P(N-1) -> P(N)

% Hallamos el caso base
palindromo([]).

% Hallamos el caso N - 1
palindromo(L) :- reverse(L,L).