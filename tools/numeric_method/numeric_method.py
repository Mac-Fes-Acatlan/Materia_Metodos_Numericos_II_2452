import abc

class NumericMethod(metaclass=abc.ABCMeta):
    
    @abc.abstractmethod
    def __init__(self,parameters:dict) -> None:
        self.parameters = parameters
    
    @abc.abstractmethod
    def parameter_validation(self)->None:
        raise NotImplementedError

    @abc.abstractmethod
    def logic_numeric_method(self):
        raise NotImplementedError

    @abc.abstractmethod
    def error_calculation(self):
        raise NotImplementedError

