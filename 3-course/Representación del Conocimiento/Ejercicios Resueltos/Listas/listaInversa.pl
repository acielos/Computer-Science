% ************************************************************************
% - Ejercicios de José A. Alonso Jiménez
% "Ejercicios de Programación Declarativa con Prolog"
%
% - Puede encontrar más información en:
% https://www.cs.us.es/~jalonso/publicaciones/2006-ej_prog_declarativa.pdf
% ************************************************************************

% ----- Lista Inversa -----
% 
% Función -> inversa(+L1, -L2)
%
% ***|Se verifica si L2 unifica con una lista que contenga los mismos
% ***|valores que L1, pero en orden inverso.
%
% --------------------------

% -- Principio de Inducción --
%
%	1. P(N0)
%	2. N > N0, P(N-1) -> P(N)

% Hallamos el caso base
inversa([], []).

% Hallamos el caso N - 1
inversa([Cab|Resto], R2) :- inversa(Resto, R), append(R, [Cab], R2).