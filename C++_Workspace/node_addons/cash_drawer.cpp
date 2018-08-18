#include <cmath>
#include <nan.h>
#include <string.h>

void Pow(const Nan::FunctionCallbackInfo<v8::Value>& info) {

    if (info.Length() < 2) {
        Nan::ThrowTypeError("Wrong number of arguments");
        return;
    }

    if (!info[0]->IsNumber() || !info[1]->IsNumber()) {
        Nan::ThrowTypeError("Both arguments should be numbers");
        return;
    }

    double arg0 = info[0]->NumberValue();
    double arg1 = info[1]->NumberValue();
    v8::Local<v8::Number> num = Nan::New(pow(arg0, arg1));

    info.GetReturnValue().Set(num);
}

void SayHello(const Nan::FunctionCallbackInfo<v8::Value> & info) {
    std::string something("hello world"); 
    v8::Handle<v8::Value> something_else = v8::String::New( something.c_str() );
    info.GetReturnValue().Set(something);
}

void Init(v8::Local<v8::Object> exports) {  
    exports->Set(Nan::New("pow").ToLocalChecked(),
                 Nan::New<v8::FunctionTemplate>(Pow)->GetFunction());
    exports->Set(Nan::New("hello").ToLocalChecked(), Nan::New<v8::FunctionTemplate>(SayHello)->GetFunction());
}

NODE_MODULE(pow, Init)