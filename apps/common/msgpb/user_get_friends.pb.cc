// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: user_get_friends.proto

#include "user_get_friends.pb.h"

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
class UserGetFriendsDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<UserGetFriends> _instance;
} _UserGetFriends_default_instance_;
}  // namespace msgpb
}  // namespace chatroom
static void InitDefaultsscc_info_UserGetFriends_user_5fget_5ffriends_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::chatroom::msgpb::_UserGetFriends_default_instance_;
    new (ptr) ::chatroom::msgpb::UserGetFriends();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
  ::chatroom::msgpb::UserGetFriends::InitAsDefaultInstance();
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_UserGetFriends_user_5fget_5ffriends_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 0, 0, InitDefaultsscc_info_UserGetFriends_user_5fget_5ffriends_2eproto}, {}};

static ::PROTOBUF_NAMESPACE_ID::Metadata file_level_metadata_user_5fget_5ffriends_2eproto[1];
static constexpr ::PROTOBUF_NAMESPACE_ID::EnumDescriptor const** file_level_enum_descriptors_user_5fget_5ffriends_2eproto = nullptr;
static constexpr ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor const** file_level_service_descriptors_user_5fget_5ffriends_2eproto = nullptr;

const ::PROTOBUF_NAMESPACE_ID::uint32 TableStruct_user_5fget_5ffriends_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::chatroom::msgpb::UserGetFriends, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::chatroom::msgpb::UserGetFriends, user_id_),
};
static const ::PROTOBUF_NAMESPACE_ID::internal::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, sizeof(::chatroom::msgpb::UserGetFriends)},
};

static ::PROTOBUF_NAMESPACE_ID::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::chatroom::msgpb::_UserGetFriends_default_instance_),
};

const char descriptor_table_protodef_user_5fget_5ffriends_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\026user_get_friends.proto\022\016chatroom.msgpb"
  "\"!\n\016UserGetFriends\022\017\n\007user_id\030\001 \001(\005b\006pro"
  "to3"
  ;
static const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable*const descriptor_table_user_5fget_5ffriends_2eproto_deps[1] = {
};
static ::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase*const descriptor_table_user_5fget_5ffriends_2eproto_sccs[1] = {
  &scc_info_UserGetFriends_user_5fget_5ffriends_2eproto.base,
};
static ::PROTOBUF_NAMESPACE_ID::internal::once_flag descriptor_table_user_5fget_5ffriends_2eproto_once;
const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_user_5fget_5ffriends_2eproto = {
  false, false, descriptor_table_protodef_user_5fget_5ffriends_2eproto, "user_get_friends.proto", 83,
  &descriptor_table_user_5fget_5ffriends_2eproto_once, descriptor_table_user_5fget_5ffriends_2eproto_sccs, descriptor_table_user_5fget_5ffriends_2eproto_deps, 1, 0,
  schemas, file_default_instances, TableStruct_user_5fget_5ffriends_2eproto::offsets,
  file_level_metadata_user_5fget_5ffriends_2eproto, 1, file_level_enum_descriptors_user_5fget_5ffriends_2eproto, file_level_service_descriptors_user_5fget_5ffriends_2eproto,
};

// Force running AddDescriptors() at dynamic initialization time.
static bool dynamic_init_dummy_user_5fget_5ffriends_2eproto = (static_cast<void>(::PROTOBUF_NAMESPACE_ID::internal::AddDescriptors(&descriptor_table_user_5fget_5ffriends_2eproto)), true);
namespace chatroom {
namespace msgpb {

// ===================================================================

void UserGetFriends::InitAsDefaultInstance() {
}
class UserGetFriends::_Internal {
 public:
};

UserGetFriends::UserGetFriends(::PROTOBUF_NAMESPACE_ID::Arena* arena)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena) {
  SharedCtor();
  RegisterArenaDtor(arena);
  // @@protoc_insertion_point(arena_constructor:chatroom.msgpb.UserGetFriends)
}
UserGetFriends::UserGetFriends(const UserGetFriends& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  user_id_ = from.user_id_;
  // @@protoc_insertion_point(copy_constructor:chatroom.msgpb.UserGetFriends)
}

void UserGetFriends::SharedCtor() {
  user_id_ = 0;
}

UserGetFriends::~UserGetFriends() {
  // @@protoc_insertion_point(destructor:chatroom.msgpb.UserGetFriends)
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

void UserGetFriends::SharedDtor() {
  GOOGLE_DCHECK(GetArena() == nullptr);
}

void UserGetFriends::ArenaDtor(void* object) {
  UserGetFriends* _this = reinterpret_cast< UserGetFriends* >(object);
  (void)_this;
}
void UserGetFriends::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void UserGetFriends::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const UserGetFriends& UserGetFriends::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_UserGetFriends_user_5fget_5ffriends_2eproto.base);
  return *internal_default_instance();
}


void UserGetFriends::Clear() {
// @@protoc_insertion_point(message_clear_start:chatroom.msgpb.UserGetFriends)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  user_id_ = 0;
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* UserGetFriends::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  ::PROTOBUF_NAMESPACE_ID::Arena* arena = GetArena(); (void)arena;
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // int32 user_id = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 8)) {
          user_id_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
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

::PROTOBUF_NAMESPACE_ID::uint8* UserGetFriends::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:chatroom.msgpb.UserGetFriends)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // int32 user_id = 1;
  if (this->user_id() != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteInt32ToArray(1, this->_internal_user_id(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:chatroom.msgpb.UserGetFriends)
  return target;
}

size_t UserGetFriends::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:chatroom.msgpb.UserGetFriends)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // int32 user_id = 1;
  if (this->user_id() != 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::Int32Size(
        this->_internal_user_id());
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
        _internal_metadata_, total_size, &_cached_size_);
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void UserGetFriends::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:chatroom.msgpb.UserGetFriends)
  GOOGLE_DCHECK_NE(&from, this);
  const UserGetFriends* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<UserGetFriends>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:chatroom.msgpb.UserGetFriends)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:chatroom.msgpb.UserGetFriends)
    MergeFrom(*source);
  }
}

void UserGetFriends::MergeFrom(const UserGetFriends& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:chatroom.msgpb.UserGetFriends)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (from.user_id() != 0) {
    _internal_set_user_id(from._internal_user_id());
  }
}

void UserGetFriends::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:chatroom.msgpb.UserGetFriends)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void UserGetFriends::CopyFrom(const UserGetFriends& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:chatroom.msgpb.UserGetFriends)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool UserGetFriends::IsInitialized() const {
  return true;
}

void UserGetFriends::InternalSwap(UserGetFriends* other) {
  using std::swap;
  _internal_metadata_.Swap<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(&other->_internal_metadata_);
  swap(user_id_, other->user_id_);
}

::PROTOBUF_NAMESPACE_ID::Metadata UserGetFriends::GetMetadata() const {
  return GetMetadataStatic();
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace msgpb
}  // namespace chatroom
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::chatroom::msgpb::UserGetFriends* Arena::CreateMaybeMessage< ::chatroom::msgpb::UserGetFriends >(Arena* arena) {
  return Arena::CreateMessageInternal< ::chatroom::msgpb::UserGetFriends >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
