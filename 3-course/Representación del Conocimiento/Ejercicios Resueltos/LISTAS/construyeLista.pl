% ************************************************************************
% - Ejercicios de José A. Alonso Jiménez
% "Ejercicios de Programación Declarativa con Prolog"
%
% - Puede encontrar más información en:
% https://www.cs.us.es/~jalonso/publicaciones/2006-ej_prog_declarativa.pdf
% ************************************************************************

% ---------- CONSTRUYE LISTA ----------
%
% Función -> cons(?X, ?L1, ?L2)
%
% ***|Se verifica si L2 unifica con la lista
% ***|L1 añadiéndole X como primer elemento
%
% ---------------------------------------

% -- Principio de Inducción --
%
%    1. P(N0)
%    2. N > N0, P(N-1) -> P(N)

% Hallamos el caso base
cons(Ele, L, [Ele|L]).

