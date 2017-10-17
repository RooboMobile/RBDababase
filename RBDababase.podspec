

Pod::Spec.new do |s|
  s.name             = 'RBDababase'
  s.version="1.0.0"
  s.summary          = 'A short description of RBDababase'
  s.description      = <<-DESC
TODO: Add long description of the pod here.
                       DESC

  s.homepage         = 'https://github.com/RooboMobile/RBDababase.git'
  s.license          = { :type => 'MIT', :file => 'LICENSE' }
  s.author           = { 'baxiang' => 'baxiang@roobo.com' }
  s.source           = { :git => 'https://github.com/RooboMobile/RBDababase.git', :tag => s.version.to_s }
  s.ios.deployment_target = '7.0'
  s.source_files = 'RBDababase/*.{h,m}'
  s.dependency 'FMDB'
end
