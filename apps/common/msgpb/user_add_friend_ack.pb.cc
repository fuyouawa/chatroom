// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: user_add_friend_ack.proto

#include "user_add_friend_ack.pb.h"

#include <algorithm>

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
namespace chatroom {
namespace msgpb {
class UserAddFriendAckDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<UserAddFriendAck> _instance;
} _UserAddFriendAck_default_instance_;
}  // namespace msgpb
}  // namespace chatroom
static void InitDefaultsscc_info_UserAddFriendAck_user_5fadd_5ffriend_5fack_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::chatroom::msgpb::_UserAddFriendAck_default_instance_;
    new (ptr) ::chatroom::msgpb::UserAddFriendAck();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
  ::chatroom::msgpb::UserAddFriendAck::InitAsDefaultInstance();
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_UserAddFriendAck_user_5fadd_5ffriend_5fack_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 0, 0, InitDefaultsscc_info_UserAddFriendAck_user_5fadd_5ffriend_5fack_2eproto}, {}};

static ::PROTOBUF_NAMESPACE_ID::Metadata file_level_metadata_user_5fadd_5ffriend_5fack_2eproto[1];
static constexpr ::PROTOBUF_NAMESPACE_ID::EnumDescriptor const** file_level_enum_descriptors_user_5fadd_5ffriend_5fack_2eproto = nullptr;
static constexpr ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor const** file_level_service_descriptors_user_5fadd_5ffriend_5fack_2eproto = nullptr;

const ::PROTOBUF_NAMESPACE_ID::uint32 TableStruct_user_5fadd_5ffriend_5fack_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::chatroom::msgpb::UserAddFriendAck, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::chatroom::msgpb::UserAddFriendAck, success_),
  PROTOBUF_FIELD_OFFSET(::chatroom::msgpb::UserAddFriendAck, errmsg_),
  PROTOBUF_FIELD_OFFSET(::chatroom::msgpb::UserAddFriendAck, friend_name_),
};
static const ::PROTOBUF_NAMESPACE_ID::internal::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, sizeof(::chatroom::msgpb::UserAddFriendAck)},
};

static ::PROTOBUF_NAMESPACE_ID::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::chatroom::msgpb::_UserAddFriendAck_default_instance_),
};

const char descriptor_table_protodef_user_5fadd_5ffriend_5fack_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\031user_add_friend_ack.proto\022\016chatroom.ms"
  "gpb\"H\n\020UserAddFriendAck\022\017\n\007success\030\001 \001(\010"
  "\022\016\n\006errmsg\030\002 \001(\t\022\023\n\013friend_name\030\003 \001(\tb\006p"
  "roto3"
  ;
static const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable*const descriptor_table_user_5fadd_5ffriend_5fack_2eproto_deps[1] = {
};
static ::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase*const descriptor_table_user_5fadd_5ffriend_5fack_2eproto_sccs[1] = {
  &scc_info_UserAddFriendAck_user_5fadd_5ffriend_5fack_2eproto.base,
};
static ::PROTOBUF_NAMESPACE_ID::internal::once_flag descriptor_table_user_5fadd_5ffriend_5fack_2eproto_once;
const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_user_5fadd_5ffriend_5fack_2eproto = {
  false, false, descriptor_table_protodef_user_5fadd_5ffriend_5fack_2eproto, "user_add_friend_ack.proto", 125,
  &descriptor_table_user_5fadd_5ffriend_5fack_2eproto_once, descriptor_table_user_5fadd_5ffriend_5fack_2eproto_sccs, descriptor_table_user_5fadd_5ffriend_5fack_2eproto_deps, 1, 0,
  schemas, file_default_instances, TableStruct_user_5fadd_5ffriend_5fack_2eproto::offsets,
  file_level_metadata_user_5fadd_5ffriend_5fack_2eproto, 1, file_level_enum_descriptors_user_5fadd_5ffriend_5fack_2eproto, file_level_service_descriptors_user_5fadd_5ffriend_5fack_2eproto,
};

// Force running AddDescriptors() at dynamic initialization time.
static bool dynamic_init_dummy_user_5fadd_5ffriend_5fack_2eproto = (static_cast<void>(::PROTOBUF_NAMESPACE_ID::internal::AddDescriptors(&descriptor_table_user_5fadd_5ffriend_5fack_2eproto)), true);
namespace chatroom {
namespace msgpb {

// ===================================================================

void UserAddFriendAck::InitAsDefaultInstance() {
}
class UserAddFriendAck::_Internal {
 public:
};

UserAddFriendAck::UserAddFriendAck(::PROTOBUF_NAMESPACE_ID::Arena* arena)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena) {
  SharedCtor();
  RegisterArenaDtor(arena);
  // @@protoc_insertion_point(arena_constructor:chatroom.msgpb.UserAddFriendAck)
}
UserAddFriendAck::UserAddFriendAck(const UserAddFriendAck& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  errmsg_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (!from._internal_errmsg().empty()) {
    errmsg_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from._internal_errmsg(),
      GetArena());
  }
  friend_name_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (!from._internal_friend_name().empty()) {
    friend_name_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from._internal_friend_name(),
      GetArena());
  }
  success_ = from.success_;
  // @@protoc_insertion_point(copy_constructor:chatroom.msgpb.UserAddFriendAck)
}

void UserAddFriendAck::SharedCtor() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&scc_info_UserAddFriendAck_user_5fadd_5ffriend_5fack_2eproto.base);
  errmsg_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  friend_name_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  success_ = false;
}

UserAddFriendAck::~UserAddFriendAck() {
  // @@protoc_insertion_point(destructor:chatroom.msgpb.UserAddFriendAck)
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

void UserAddFriendAck::SharedDtor() {
  GOOGLE_DCHECK(GetArena() == nullptr);
  errmsg_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  friend_name_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

void UserAddFriendAck::ArenaDtor(void* object) {
  UserAddFriendAck* _this = reinterpret_cast< UserAddFriendAck* >(object);
  (void)_this;
}
void UserAddFriendAck::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void UserAddFriendAck::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const UserAddFriendAck& UserAddFriendAck::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_UserAddFriendAck_user_5fadd_5ffriend_5fack_2eproto.base);
  return *internal_default_instance();
}


void UserAddFriendAck::Clear() {
// @@protoc_insertion_point(message_clear_start:chatroom.msgpb.UserAddFriendAck)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  errmsg_.ClearToEmpty(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
  friend_name_.ClearToEmpty(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
  success_ = false;
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* UserAddFriendAck::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  ::PROTOBUF_NAMESPACE_ID::Arena* arena = GetArena(); (void)arena;
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // bool success = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 8)) {
          success_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // string errmsg = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 18)) {
          auto str = _internal_mutable_errmsg();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "chatroom.msgpb.UserAddFriendAck.errmsg"));
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // string friend_name = 3;
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 26)) {
          auto str = _internal_mutable_friend_name();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "chatroom.msgpb.UserAddFriendAck.friend_name"));
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      default: {
      handle_unusual:
        if ((tag & 7) == 4 || tag == 0) {
          ctx->SetLastTag(tag);
          goto success;
        }
        ptr = UnknownFieldParse(tag,
            _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
            ptr, ctx);
        CHK_(ptr != nullptr);
        continue;
      }
    }  // switch
  }  // while
success:
  return ptr;
failure:
  ptr = nullptr;
  goto success;
#undef CHK_
}

::PROTOBUF_NAMESPACE_ID::uint8* UserAddFriendAck::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:chatroom.msgpb.UserAddFriendAck)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // bool success = 1;
  if (this->success() != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteBoolToArray(1, this->_internal_success(), target);
  }

  // string errmsg = 2;
  if (this->errmsg().size() > 0) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_errmsg().data(), static_cast<int>(this->_internal_errmsg().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "chatroom.msgpb.UserAddFriendAck.errmsg");
    target = stream->WriteStringMaybeAliased(
        2, this->_internal_errmsg(), target);
  }

  // string friend_name = 3;
  if (this->friend_name().size() > 0) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_friend_name().data(), static_cast<int>(this->_internal_friend_name().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "chatroom.msgpb.UserAddFriendAck.friend_name");
    target = stream->WriteStringMaybeAliased(
        3, this->_internal_friend_name(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:chatroom.msgpb.UserAddFriendAck)
  return target;
}

size_t UserAddFriendAck::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:chatroom.msgpb.UserAddFriendAck)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // string errmsg = 2;
  if (this->errmsg().size() > 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_errmsg());
  }

  // string friend_name = 3;
  if (this->friend_name().size() > 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_friend_name());
  }

  // bool success = 1;
  if (this->success() != 0) {
    total_size += 1 + 1;
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
        _internal_metadata_, total_size, &_cached_size_);
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void UserAddFriendAck::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:chatroom.msgpb.UserAddFriendAck)
  GOOGLE_DCHECK_NE(&from, this);
  const UserAddFriendAck* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<UserAddFriendAck>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:chatroom.msgpb.UserAddFriendAck)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:chatroom.msgpb.UserAddFriendAck)
    MergeFrom(*source);
  }
}

void UserAddFriendAck::MergeFrom(const UserAddFriendAck& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:chatroom.msgpb.UserAddFriendAck)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (from.errmsg().size() > 0) {
    _internal_set_errmsg(from._internal_errmsg());
  }
  if (from.friend_name().size() > 0) {
    _internal_set_friend_name(from._internal_friend_name());
  }
  if (from.success() != 0) {
    _internal_set_success(from._internal_success());
  }
}

void UserAddFriendAck::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:chatroom.msgpb.UserAddFriendAck)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void UserAddFriendAck::CopyFrom(const UserAddFriendAck& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:chatroom.msgpb.UserAddFriendAck)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool UserAddFriendAck::IsInitialized() const {
  return true;
}

void UserAddFriendAck::InternalSwap(UserAddFriendAck* other) {
  using std::swap;
  _internal_metadata_.Swap<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(&other->_internal_metadata_);
  errmsg_.Swap(&other->errmsg_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
  friend_name_.Swap(&other->friend_name_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
  swap(success_, other->success_);
}

::PROTOBUF_NAMESPACE_ID::Metadata UserAddFriendAck::GetMetadata() const {
  return GetMetadataStatic();
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace msgpb
}  // namespace chatroom
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::chatroom::msgpb::UserAddFriendAck* Arena::CreateMaybeMessage< ::chatroom::msgpb::UserAddFriendAck >(Arena* arena) {
  return Arena::CreateMessageInternal< ::chatroom::msgpb::UserAddFriendAck >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>