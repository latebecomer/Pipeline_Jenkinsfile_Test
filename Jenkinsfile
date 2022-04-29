pipeline {
    agent any

    stages {

		stage('Install') {
			steps {
				bat 'C:/BuildEngine/Scripts/Echo.bat Installing...'
				bat 'C:/BuildEngine/Scripts/Install.bat'
			}
		}
		stage('Run') {
			steps {
				bat 'C:/BuildEngine/Scripts/Echo.bat Running...'
				script{
			        withEnv(['JENKINS_NODE_COOKIE=dontkill']) {
				        bat 'C:/BuildEngine/Scripts/Run.bat'
			        }
			    }	
			}
		}
    }
	
	post {
		always {
			// This path takes WORKSPACE implicitly upfront, which for me is C:/Personal/Install/workspace/FirstPipeline/. 
			junit 'Reports/**/*.xml'
		}
	}
}