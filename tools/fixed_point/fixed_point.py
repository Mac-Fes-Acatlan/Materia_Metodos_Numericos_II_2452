import numeric_method.numeric_method as numeric_method
import math


class FixedPoint(numeric_method.NumericMethod):
    def __init__(self, parameters: dict) -> None:

        super().__init__(parameters)

    def parameter_validation(self) -> None:
        pass

    def logic_numeric_method(self):

        for i in range(14):
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
            print(
                self.parameters["vector_iterator"][0],
                self.parameters["vector_iterator"][1],
                self.parameters["vector_iterator"][2],
            )
            print("\n")

    def error_calculation(self):
        pass
