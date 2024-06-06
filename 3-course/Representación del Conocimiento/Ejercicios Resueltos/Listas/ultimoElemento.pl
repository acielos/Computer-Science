% ************************************************************************
% - Ejercicios de José A. Alonso Jiménez
% "Ejercicios de Programación Declarativa con Prolog"
%
% - Puede encontrar más información en:
% https://www.cs.us.es/~jalonso/publicaciones/2006-ej_prog_declarativa.pdf
% ************************************************************************

% ----- Último Elemento -----
% 
% Función -> ultimoElemento(?X, ?L)
%
% ***|Se verifica si X unifica con el elemento final de L
%
% --------------------------

% -- Principio de Inducción --
%
%	1. P(N0)
%	2. N > N0, P(N-1) -> P(N)

% Hallamos el caso base
ultimoElemento(Ult, [Ult]).

% Hallamos el caso N - 1
ultimoElemento(Ele, [_|Resto]) :- ultimoElemento(Ele, Resto).