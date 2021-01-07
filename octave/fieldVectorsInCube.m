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

    numCountPoitPerDirection = 5;
    step = scaleCoef / numCountPoitPerDirection;

    vIterator = center - n .* scaleCoef ./ 2 .- v .* scaleCoef ./ 2 .- u .* scaleCoef ./ 2;
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

function [facersCube] = calculateFacetsCube (cubeWhd)
    facersCube = [];

    xzN = [1, 0, 0];
    yzN = [0, 1, 0];
    xyN = [0, 0, 1];

    facersCube = [facersCube; [xzN, 0]];
    facersCube = [facersCube; [xzN, -1]];

    facersCube = [facersCube; [yzN, 0]];
    facersCube = [facersCube; [yzN, -1]];

    facersCube = [facersCube; [xyN, 0]];
    facersCube = [facersCube; [xyN, -1]];
endfunction

function [intersectionPoints] = calculateIntersectionPoints (fieldVectorsBegin, v, u, facersCube)
    intersectionPoints = [];
    for i = 1:rows(fieldVectorsBegin)
        straightLineEquation1 = [v, -sum(v .* fieldVectorsBegin(i, :))];
        straightLineEquation2 = [u, -sum(u .* fieldVectorsBegin(i, :))];

        fieldVectorIntersectionPoints = [];
        for j = 1:rows(facersCube)
            slae = [facersCube(j, :); straightLineEquation1; straightLineEquation2];

            mainSlae = [slae(:, 1), slae(:, 2), slae(:, 3)];
            if (sum(slae(1, :) .* slae(2, :)) == 0 || sum(slae(1, :) .* slae(2, :)) == 0)
                continue;
            endif

            mainDet = det(mainSlae);
            if(mainDet == 0)
                continue;
            endif

            xSlae = [slae(:, 4) .* -1, slae(:, 2), slae(:, 3)];
            xDet = det(xSlae);

            ySlae = [slae(:, 1), slae(:, 4) .* -1, slae(:, 3)];
            yDet = det(ySlae);

            zSlae = [slae(:, 1), slae(:, 2), slae(:, 4) .* -1];
            zDet = det(zSlae);

            fieldVectorIntersectionPoints = [fieldVectorIntersectionPoints; [xDet / mainDet, yDet / mainDet, zDet / mainDet]];
        endfor
        intersectionPoints{i} = fieldVectorIntersectionPoints;
    endfor
endfunction

function [fieldVectorsBegin, fieldVectorsEnd] = calculateOnCubeIntersectionPoints (intersectionPoints, cubeWhd)
    fieldVectorsBegin = [];
    fieldVectorsEnd = [];

    for i = 1:numel(intersectionPoints)
        pointsOnCube = [];
        for j = 1:rows(intersectionPoints{i})
            if (intersectionPoints{i}(j, 1) >= 0 && intersectionPoints{i}(j, 2) >= 0 && intersectionPoints{i}(j, 3) >= 0)
                if(intersectionPoints{i}(j, 1) <= cubeWhd(1) && intersectionPoints{i}(j, 2) <= cubeWhd(2) && intersectionPoints{i}(j, 3) <= cubeWhd(3))
                    pointsOnCube = [pointsOnCube; intersectionPoints{i}(j, :)];
                endif
            endif
        endfor

        if(rows(pointsOnCube) > 1)
            fieldVectorsBegin = [fieldVectorsBegin; pointsOnCube(1, :)];
            fieldVectorsEnd = [fieldVectorsEnd; pointsOnCube(2, :)];
        endif
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
    for i = 1:1:rows(fieldVectorsBegin)
        plot3([fieldVectorsBegin(i, 1), fieldVectorsEnd(i, 1)], [fieldVectorsBegin(i, 2), fieldVectorsEnd(i, 2)], [fieldVectorsBegin(i, 3), fieldVectorsEnd(i, 3)], 'm');
        hold on;
    endfor
endfunction

%[x, y, z] = sphere (40);
%surf (x * 0.5 + 0.5, y * 0.5 + 0.5, z * 0.5 + 0.5);
%hold on;

direction = [1, 0, 0];
[v, u, n] = calculateSpaceBasis(direction);

v = [0, 1, 0];
u = [0, 0, 1];
drawDirectionAndPlaneBasis(v, u, n);

cubeWhd = [1, 1, 1];
[fieldVectorsBegin, fieldVectorsEnd] = calculateFieldVectors(v, u, n, cubeWhd);
[facetesCube] = calculateFacetsCube(cubeWhd);
[intersectionPoints] = calculateIntersectionPoints(fieldVectorsBegin, v, u, facetesCube);
[fieldVectorsBegin, fieldVectorsEnd] = calculateOnCubeIntersectionPoints(intersectionPoints, cubeWhd);
%drawField(fieldVectorsBegin, fieldVectorsEnd);
