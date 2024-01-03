protoc --cpp_out=../server/include/message --proto_path=./proto ./proto/*
mv ../server/include/message/*.cc ../server/src/message/