1;

% Построение параллельных векторов в выбранном направлении,
% для демонстрации полей непосредственно в моделируемом пространстве

function [v, u] = calculatePlaneBasis (n)
    % Вычисление базиса плоскости заданной нормальным вектором
    v = rand(1, 3) .+ 1;
    if (n(1) ~= 0)
        v(1) = -1 * (n(2) * v(2) + n(3) * v(3)) / n(1);
    elseif (n(2) ~= 0)
        v(2) = -1 * (n(1) * v(1) + n(3) * v(3)) / n(2);
    elseif (n(3) ~= 0)
        v(3) = -1 * (n(1) * v(1) + n(2) * v(2)) / n(3);
    endif
    v = v ./ norm(v);

    nNotNullIndex = find(n(:) > 0, 1);
    vNotNullIndex = find(v(:) > 0, 1);
    if (vNotNullIndex == nNotNullIndex)
        vNotNullIndex = find(v(vNotNullIndex + 1:end) > 0, 1) + vNotNullIndex;
    endif
    uRandIndex = 1 + 2 + 3 - nNotNullIndex - vNotNullIndex;

    nvCoeff = v(nNotNullIndex) / (n(nNotNullIndex) * v(vNotNullIndex));

    u = rand(1, 3) .+ 1;
    u(vNotNullIndex) = u(uRandIndex) * (n(uRandIndex) * nvCoeff - v(uRandIndex) / v(vNotNullIndex)) / ( 1 - n(vNotNullIndex) * nvCoeff );
    u(nNotNullIndex) = -1 * (u(vNotNullIndex) * n(vNotNullIndex) + u(uRandIndex) * n(uRandIndex)) / n(nNotNullIndex);
    u = u ./ norm(u);
endfunction

function [v, u, n] = calculateSpaceBasis(direction)
    n = direction ./ norm(direction);
    [v, u] = calculatePlaneBasis(n);
endfunction

function [fieldVectorsBegin, fieldVectorsEnd] = calculateFieldVectors(v, u, n, spaceWhd)
    fieldVectorsBegin = [];
    fieldVectorsEnd = [];

    center = spaceWhd ./ 2;
    maxLinearSize = max(spaceWhd);
    scaleCoef = 2 * maxLinearSize; %  / norm(n) = 1

    numCountPoitPerDirection = 10;
    step = scaleCoef / numCountPoitPerDirection;

    vIterator = center - n .* scaleCoef ./ 2 .- v .* scaleCoef ./ 2 .- u .* scaleCoef ./ 2
    for i = 1:numCountPoitPerDirection + 1
        uIterator = vIterator;
        for j = 1:numCountPoitPerDirection + 1
            fieldVectorsBegin = [fieldVectorsBegin; uIterator];
            fieldVectorsEnd = [fieldVectorsEnd; uIterator + n .* scaleCoef];

            uIterator = uIterator + u .* step;
        endfor
        vIterator = vIterator + v .* step;
    endfor

endfunction

function drawDirectionAndPlaneBasis (v, u ,n)
    directionColor = 'blue';

    directionQuiver = quiver3(0, 0, 0, n(1), n(2), n(3));
    set(directionQuiver, 'Color', directionColor);
    hold on;

    scatter3([0], [0], [0]);
    hold on;

    vQuiver = quiver3(0, 0, 0, v(1), v(2), v(3));
    set(vQuiver, 'Color', 'Red');
    hold on;

    uQuiver = quiver3(0, 0, 0, u(1), u(2), u(3));
    set(uQuiver, 'Color', 'Green');
    hold on;
endfunction

function drawField (fieldVectorsBegin, fieldVectorsEnd)
    for i = 1:1:length(fieldVectorsBegin)
        plot3([fieldVectorsBegin(i, 1), fieldVectorsEnd(i, 1)], [fieldVectorsBegin(i, 2), fieldVectorsEnd(i, 2)], [fieldVectorsBegin(i, 3), fieldVectorsEnd(i, 3)], 'm');
        hold on;
    endfor
endfunction

[x, y, z] = sphere (40);
surf (x * 0.5 + 0.5, y * 0.5 + 0.5, z * 0.5 + 0.5);
hold on;

direction = [1, 2, 3];
[v, u, n] = calculateSpaceBasis(direction);

drawDirectionAndPlaneBasis(v, u, n);

cubeWhd = [1, 1, 1];
[fieldVectorsBegin, fieldVectorsEnd] = calculateFieldVectors(v, u, n, cubeWhd)
drawField(fieldVectorsBegin, fieldVectorsEnd);
