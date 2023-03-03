import tools.numeric_method.numeric_method as numeric_method
import math
import pandas as pd


class FixedPoint(numeric_method.NumericMethod):
    def __init__(self, parameters: dict) -> None:

        super().__init__(parameters)

    def parameter_validation(self) -> None:
        pass

    def logic_numeric_method(self):

        lst_errors = []

        while True:

            # ==================Logic Method==================START

            self.parameters["vector_aux"][0] = (
                1
                / 3
                * (
                    math.cos(
                        self.parameters["vector_iterator"][1]
                        * self.parameters["vector_iterator"][2]
                    )
                )
                + 1 / 6
            )
            self.parameters["vector_aux"][1] = (
                1
                / 9
                * math.sqrt(
                    math.pow(self.parameters["vector_iterator"][0], 2)
                    + math.sin(self.parameters["vector_iterator"][2])
                    + 1.06
                )
                - 0.1
            )
            self.parameters["vector_aux"][2] = -1 / 20 * (
                math.exp(
                    (-1)
                    * self.parameters["vector_iterator"][0]
                    * self.parameters["vector_iterator"][1]
                )
            ) - (((10 * math.pi) - 3) / (60))

            # ==================Logic Method==================END

            error_value = self.error_calculation(
                tuple(self.parameters["vector_iterator"]),
                tuple(self.parameters["vector_aux"]),
            )

            lst_errors.append(error_value)

            (
                self.parameters["vector_iterator"][0],
                self.parameters["vector_iterator"][1],
                self.parameters["vector_iterator"][2],
            ) = (
                self.parameters["vector_aux"][0],
                self.parameters["vector_aux"][1],
                self.parameters["vector_aux"][2],
            )

            self.parameters["table_output"]["x1"].append(
                self.parameters["vector_iterator"][0]
            )

            self.parameters["table_output"]["x2"].append(
                self.parameters["vector_iterator"][1]
            )

            self.parameters["table_output"]["x3"].append(
                self.parameters["vector_iterator"][2]
            )

            if (error_value <= 0.000001) and (error_value != 0.0):
                break

        df_data_punto_fijo = pd.DataFrame(
            {
                "x1": self.parameters["table_output"]["x1"],
                "x2": self.parameters["table_output"]["x2"],
                "x3": self.parameters["table_output"]["x3"],
                "error": lst_errors,
            }
        )

        print(df_data_punto_fijo)

    def error_calculation(self, vector_before, vector_after):
        return math.dist(vector_before, vector_after)
