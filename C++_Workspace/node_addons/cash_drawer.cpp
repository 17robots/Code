#include <nan.h>
#include <cmath>

const int maxValue = 10;
int numberOfCalls = 0;

NAN_METHOD(whoami) {
  auto message = Nan::New<v8::String>("I'm a Node Hero!").ToLocalChecked();
  info.GetReturnValue().Set(message);
}

NAN_METHOD(Pow) {
  if(info.Length() > 2 || info.Length() < 2) {
    Nan::ThrowError("There must be two arguments");
    return;
  } else if(!info[0]->IsNumber() || !info[1]->IsNumber()) {
    Nan::ThrowError("Arguments must be numbers");
    return;
  }

  auto answer = Nan::New<v8::Number>(pow(info[0]->NumberValue(), info[1]->NumberValue()));

  info.GetReturnValue().Set(answer);
}

NAN_METHOD(increment) {
  if (!info[0]->IsNumber()) {
    Nan::ThrowError("Argument must be a number");
    return;
  }

  double infoValue = info[0]->NumberValue();
  if (numberOfCalls + infoValue > maxValue) {
    Nan::ThrowError("Counter went through the roof!");
    return;
  }

  numberOfCalls += infoValue;

  auto currentNumberOfCalls =
    Nan::New<v8::Number>(numberOfCalls);

  info.GetReturnValue().Set(currentNumberOfCalls);
}

NAN_MODULE_INIT(Initialize) {
  NAN_EXPORT(target, whoami);
  NAN_EXPORT(target, increment);
  NAN_EXPORT(target, Pow);
}

NODE_MODULE(addon, Initialize);