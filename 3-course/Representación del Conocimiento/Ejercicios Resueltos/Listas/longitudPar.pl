% ************************************************************************
% - Ejercicios de José A. Alonso Jiménez
% "Ejercicios de Programación Declarativa con Prolog"
%
% - Puede encontrar más información en:
% https://www.cs.us.es/~jalonso/publicaciones/2006-ej_prog_declarativa.pdf
% ************************************************************************

% ----- LONGITUD PAR DE LISTA -----
% 
% Función -> longitudPar(+Lis)
%
% ***|Se verifica si la longitud de Lis es par
%
% --------------------------

% -- Principio de Inducción --
%
%	1. P(N0)
%	2. N > N0, P(N-1) -> P(N)

% Hallamos el caso base
longitudPar([_, _]).

% Hallamos el caso N - 1
longitudPar([_, _|Resto]) :- longitudPar(Resto).