% ************************************************************************
% - Ejercicios de José A. Alonso Jiménez
% "Ejercicios de Programación Declarativa con Prolog"
%
% - Puede encontrar más información en:
% https://www.cs.us.es/~jalonso/publicaciones/2006-ej_prog_declarativa.pdf
% ************************************************************************

% ----- Resto de una Lista -----
% 
% Función -> resto(?L1, ?L2)
%
% ***|Se verifica si L2 es la lista a partir de la lista L1,
% ***|quitando la cabecera
%
%---------------------------

% Principio de Inducción
%
%	1. P(N0)
%	2. N > N0, P(N-1) -> P(N)

% Hallamos el caso base
resto([_|Resto], Resto).