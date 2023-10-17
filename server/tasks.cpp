
#include "tasks.h"
#include <QRandomGenerator>
#include <QString>
#include <vector>
#include <QVariantMap>

int randomInt(int min, int max) {
    return QRandomGenerator::global()->bounded(min, max + 1);
}

std::vector<std::vector<int>> generateMatrix3x3() {
    std::vector<std::vector<int>> matrix(3, std::vector<int>(3));

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            matrix[i][j] = randomInt(-10, 10);
        }
    }

    return matrix;
}

int determinant3x3(const std::vector<std::vector<int>>& matrix) {
    return matrix[0][0] * (matrix[1][1] * matrix[2][2] - matrix[2][1] * matrix[1][2])
           - matrix[0][1] * (matrix[1][0] * matrix[2][2] - matrix[1][2] * matrix[2][0])
           + matrix[0][2] * (matrix[1][0] * matrix[2][1] - matrix[1][1] * matrix[2][0]);
}

QString matrixToString(const std::vector<std::vector<int>>& matrix) {
    QString result;
    for (const auto& row : matrix) {
        for (int value : row) {
            result += QString::number(value) + "\t";
        }
        result += "\n";
    }
    return result;
}

QVariantMap generateMatrixTask() {
    QVariantMap task;

    auto matrix = generateMatrix3x3();

    int det = determinant3x3(matrix);

    task["text"] = QString("Вычислите определитель следующей матрицы:\nМатрица A:\n%1").arg(matrixToString(matrix));
    task["answer"] = QString("%1").arg(det);

    return task;
}

