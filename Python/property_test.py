class Backbone:
    def __init__(self) -> None:
        self.recorder = {"1": 1, "2": 2}

class Model:
    def __init__(self) -> None:
        self.backbone = Backbone()

    # 让模型拥有这个属性
    @property
    def recorder(self):
        return self.backbone.recorder

    # 这个属性赋值的方式
    @recorder.setter
    def recorder(self, value):
        self.backbone.recorder = value

if __name__ == "__main__":
    model = Model()
    recorder = model.recorder
    print(f"get_recorder {recorder}")
    model.recorder = {}
    print(f"get_recorder {model.backbone.recorder}")
    is_has = "Yes" if hasattr(model, "recorder") else "No"
    is_get = "Yes" if getattr(model, "recorder", None) is not None else "No"
    print(f"model has recorder {is_has}")
    print(f"model get recorder {is_get}")

