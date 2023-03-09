import tools.numeric_method.numeric_method as numeric_method
import numpy as np
import pandas as pd
import math


class Newton(numeric_method.NumericMethod):
    def __init__(self, parameters: dict) -> None:

        super().__init__(parameters)

    def parameter_validation(self) -> None:
        pass

    def logic_numeric_method(self):

        for i in range(6):
            Jacobiana = np.matrix(
                [
                    [
                        3,
                        self.parameters["vector_iterator"][2]
                        * math.sin(
                            self.parameters["vector_iterator"][1]
                            * self.parameters["vector_iterator"][2]
                        ),
                        self.parameters["vector_iterator"][1]
                        * math.sin(
                            self.parameters["vector_iterator"][1]
                            * self.parameters["vector_iterator"][2]
                        ),
                    ],
                    [
                        2 * self.parameters["vector_iterator"][0],
                        -162 * (self.parameters["vector_iterator"][1] + 0.1),
                        math.cos(self.parameters["vector_iterator"][2]),
                    ],
                    [
                        (-1 * (self.parameters["vector_iterator"][1]))
                        * (
                            math.exp(
                                (-1)
                                * self.parameters["vector_iterator"][0]
                                * self.parameters["vector_iterator"][1]
                            )
                        ),
                        (-1 * (self.parameters["vector_iterator"][0]))
                        * (
                            math.exp(
                                (-1)
                                * self.parameters["vector_iterator"][0]
                                * self.parameters["vector_iterator"][1]
                            )
                        ),
                        20,
                    ],
                ]
            )

            Funcion = np.matrix(
                [
                    [
                        (3 * (self.parameters["vector_iterator"][0]))
                        - (
                            math.cos(
                                self.parameters["vector_iterator"][1]
                                * self.parameters["vector_iterator"][2]
                            )
                        )
                        - 0.5
                    ],
                    [
                        (math.pow(self.parameters["vector_iterator"][0], 2))
                        - (
                            (81)
                            * (
                                math.pow(
                                    (self.parameters["vector_iterator"][1] + 0.1), 2
                                )
                            )
                        )
                        + (math.sin(self.parameters["vector_iterator"][2]))
                        + 1.06
                    ],
                    [
                        (
                            math.exp(
                                (-1)
                                * self.parameters["vector_iterator"][0]
                                * self.parameters["vector_iterator"][1]
                            )
                        )
                        + 20 * (self.parameters["vector_iterator"][2])
                        + (((10 * math.pi) - 3) / (3))
                    ],
                ]
            )

            Funcion = -1 * Funcion

            y = (Jacobiana**-1) * Funcion

            solucion = (
                np.matrix(
                    [
                        [self.parameters["vector_iterator"][0]],
                        [self.parameters["vector_iterator"][1]],
                        [self.parameters["vector_iterator"][2]],
                    ]
                )
                + y
            )

            # asignacion aux

            self.parameters["vector_iterator"] = [
                solucion.tolist()[0][0],
                solucion.tolist()[1][0],
                solucion.tolist()[2][0],
            ]
            print(self.parameters["vector_iterator"])

    def error_calculation(self, vector_before, vector_after):
        return math.dist(vector_before, vector_after)
