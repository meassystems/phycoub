1;

function [v, u] = calculatePlaneBasis (planeNorm)
    v = rand(1, 3) .+ 1;
    if (planeNorm(1) ~= 0)
        v(1) = -1 * (planeNorm(2) * v(2) + planeNorm(3) * v(3)) / planeNorm(1);
    elseif (planeNorm(2) ~= 0)
        v(2) = -1 * (planeNorm(1) * v(1) + planeNorm(3) * v(3)) / planeNorm(2);
    elseif (planeNorm(3) ~= 0)
        v(3) = -1 * (planeNorm(1) * v(1) + planeNorm(2) * v(2)) / planeNorm(3);
    endif
    v = v ./ norm(v);

    uHelper = [planeNorm(1) - v(1), planeNorm(2) - v(2), planeNorm(3) - v(3)];
    u = rand(1, 3) .+ 1;
    if (uHelper(1) ~= 0)
        u(1) = -1 * (uHelper(2) * u(2) + uHelper(3) * u(3)) / uHelper(1);
    elseif (uHelper(2) ~= 0)
        u(2) = -1 * (uHelper(1) * u(1) + uHelper(3) * u(3)) / uHelper(2);
    elseif (uHelper(3) ~= 0)
        u(3) = -1 * (uHelper(1) * u(1) + uHelper(2) * u(2)) / uHelper(3);
    endif
    u = u ./ norm(u);
endfunction

directionColor = 'blue';

direction = [0, 0, 1];
normDirection = direction ./ norm(direction);
directionQuiver = quiver3(0, 0, 0, normDirection(1), normDirection(2), normDirection(3));
set(directionQuiver, 'Color', directionColor);
hold on;

directionScatter = scatter3([0], [0], [0]);
hold on;

[v, u] = calculatePlaneBasis(normDirection)
vQuiver = quiver3(0, 0, 0, v(1), v(2), v(3));
set(vQuiver, 'Color', 'Red');
hold on;

uQuiver = quiver3(0, 0, 0, u(1), u(2), u(3));
set(uQuiver, 'Color', 'Green');
hold on;

%set(quiversensorx, 'LineWidth', 1);
%set(quiversensory, 'LineWidth', 1);
%set(quiversensorz, 'LineWidth', 1);
%
%axis equal
%
%textx = text(5, 0, 1, 'This is the x-vector')
%set(textx, 'Color', 'blue')

hold off;