protoc --cpp_out=../server/include/message --proto_path=../proto/message ../proto/message/*
mv ../server/include/message/*.cc ../server/src/message/