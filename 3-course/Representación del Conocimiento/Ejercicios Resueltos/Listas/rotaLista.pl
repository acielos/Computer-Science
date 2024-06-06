% ************************************************************************
% - Ejercicios de José A. Alonso Jiménez
% "Ejercicios de Programación Declarativa con Prolog"
%
% - Puede encontrar más información en:
% https://www.cs.us.es/~jalonso/publicaciones/2006-ej_prog_declarativa.pdf
% ************************************************************************

% ----- ROTACION ELEMENTO -----
% 
% Función -> rotacion(?Lis1, ?Lis2)
%
% ***|Se verifica si Lis2 es igual que Lis1, pero con el primer elmento
% ***|al final
%
% --------------------------

% -- Principio de Inducción --
%
%	1. P(N0)
%	2. N > N0, P(N-1) -> P(N)

% Hallamos el caso base


% Hallamos el caso N - 1
rotacion([Cab|Resto], Lis2) :- append(Resto, [Cab], Lis2).