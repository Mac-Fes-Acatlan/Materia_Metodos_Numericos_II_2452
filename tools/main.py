from fixed_point.fixed_point import FixedPoint
from typing import Dict

if __name__ == "__main__":

    parameters = {}
    parameters["vector_iterator"] = [0.0, 0.0, 0.0]
    parameters["vector_aux"] = [0.0, 0.0, 0.0]
    parameters["table_output"] = {"x1": [], "x2": [], "x3": []}

    fixed_point = FixedPoint(parameters)
    fixed_point.logic_numeric_method()
